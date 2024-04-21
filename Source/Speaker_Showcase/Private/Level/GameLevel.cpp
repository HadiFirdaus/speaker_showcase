// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevel.h"
#include "Camera/CameraActor.h"
#include "MainDisplay.h"
#include "SpeakerInfo.h"
#include "CameraNameInfo.h"
#include "GameFramework/PlayerController.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"

void AGameLevel::BeginPlay()
{
	Super::BeginPlay();
}

UMainDisplay * AGameLevel::GetMainDisplay()
{
	if (MainDisplayClass) {
		MainDisplay = CreateWidget<UMainDisplay>(GetWorld(), MainDisplayClass);
		if (MainDisplay) {
			return MainDisplay;
		}
	}
	return MainDisplay;
}

void AGameLevel::CamNameToWidget(int32 Index)
{
	FString IntStr = FString::FromInt(Index);
	FName RowName = FName(*IntStr);
	FCameraNameInfo* CameraDataTable = CameraName_Table->FindRow<FCameraNameInfo>(RowName, "");
	MainDisplayReference->SetCameraName(CameraDataTable->CameraName);
}

void AGameLevel::GoToCamera(int32 CameraInt)
{
	CamNameToWidget(CameraInt);
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->SetViewTargetWithBlend(CameraArray[CameraInt], CameraBlendTime, EViewTargetBlendFunction::VTBlend_EaseInOut, 1.0f);
}

void AGameLevel::CameraTransition()
{
	if (IsCameraAllowed) {
		MainDisplayReference->PlayButtonAudio(MainDisplayReference->GetClickAux());
		IsCameraAllowed = false;
		if (IsCameraUp) {
			GoToCamera(NumOfCamera = (NumOfCamera + 1) % MaxCamera);
		}
		else {
			NumOfCamera = NumOfCamera - 1;
			if (NumOfCamera > -1) {
				GoToCamera(NumOfCamera);
			}
			else if(NumOfCamera ==-1){
				NumOfCamera = MaxCamera - 1;
				GoToCamera(NumOfCamera);
			}
			else if(NumOfCamera < -1){
				NumOfCamera = MaxCamera - 1;
				GoToCamera(NumOfCamera);
			}
		}
	}
	else {
		MainDisplayReference->PlayButtonAudio(MainDisplayReference->GetFailClickAux());
	}
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &AGameLevel::Delay, CameraBlendTime, false);
}

void AGameLevel::InitializeCameraLevel(AActor * CamTarget)
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->SetViewTargetWithBlend(CamTarget);
	MaxCamera = CameraArray.Num();
	CamNameToWidget(0);
	MainDisplayReference->CameraNext_Dispatcher.AddDynamic(this, &AGameLevel::CameraNextButton);
	MainDisplayReference->CameraPrevious_Dispatcher.AddDynamic(this, &AGameLevel::CameraPreviousButton);
}

void AGameLevel::CameraNextButton()
{
	IsCameraUp = true;
	CameraTransition();
}

void AGameLevel::CameraPreviousButton()
{
	IsCameraUp = false;
	CameraTransition();
}

void AGameLevel::Delay()
{
	IsCameraAllowed = true;
}
