// Fill out your copyright notice in the Description page of Project Settings.


#include "MainDisplay.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "AudioDevice.h"
#include "ActiveSound.h"
#include "Logic.h"

UMainDisplay::UMainDisplay(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

bool UMainDisplay::Initialize()
{
	Super::Initialize();
	//Should be one function with parameter var
	BasePriceText->TextDelegate.BindUFunction(this, "GetBasePrice");
	SpeakerChoiceText->TextDelegate.BindUFunction(this, "GetSpeakerChoice");
	SpeakerPriceText->TextDelegate.BindUFunction(this, "GetSpeakerPrice");
	CabinetChoiceText->TextDelegate.BindUFunction(this, "GetCabinetChoice");
	CabinetPriceText->TextDelegate.BindUFunction(this, "GetCabinetPrice");
	AccentChoiceText->TextDelegate.BindUFunction(this, "GetAccentChoice");
	AccentPriceText->TextDelegate.BindUFunction(this, "GetAccentPrice");
	ScreenChoiceText->TextDelegate.BindUFunction(this, "GetScreenChoice");
	ScreenPriceText->TextDelegate.BindUFunction(this, "GetScreenPrice");
	TotalPriceText->TextDelegate.BindUFunction(this, "GetTotalPrice");
	DescriptionText->TextDelegate.BindUFunction(this, "GetDescription");
	AwaitDataText->TextDelegate.BindUFunction(this, "GetCameraName");

	ExitButton->OnClicked.AddUniqueDynamic(this, &UMainDisplay::QuitGame);
	NextButton->OnClicked.AddUniqueDynamic(this, &UMainDisplay::CameraNextEvent);
	PreviousButton->OnClicked.AddUniqueDynamic(this, &UMainDisplay::CameraPreviousEvent);
	TrackOneButton->OnClicked.AddUniqueDynamic(this, &UMainDisplay::PlayTrackOne);
	TrackTwoButton->OnClicked.AddUniqueDynamic(this, &UMainDisplay::PlayTrackTwo);
	TrackThreeButton->OnClicked.AddUniqueDynamic(this, &UMainDisplay::PlayTrackThree);
	return true;
}

void UMainDisplay::InitializeMainDisplayClass_Implementation(ALogic * LogicRef)
{
	//Override in BP
}

void UMainDisplay::PlayButtonAudio(USoundBase * ButtonAudio)
{
	UWorld* ThisWorld = GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::LogAndReturnNull);
	//if (ThisWorld) {
	//	FAudioDevice* AudioDevice = ThisWorld->GetAudioDevice();
	//	if (AudioDevice) {
	//		FActiveSound NewActiveSound;
	//		NewActiveSound.SetSound(ButtonAudio);
	//		NewActiveSound.SetWorld(ThisWorld);
	//		NewActiveSound.Priority = ClickAudio->Priority;
	//		AudioDevice->AddNewActiveSound(NewActiveSound);
	//	}
	//}
}

FText UMainDisplay::GetSpeakerChoice() const
{
	//return SpeakerChoice;
	return MainComponents[3].Choice;
}

FText UMainDisplay::GetSpeakerPrice() const
{
	//return SpeakerPrice;
	return MainComponents[3].Price;
}

FText UMainDisplay::GetCabinetChoice() const
{
	//return CabinetChoice;
	return MainComponents[1].Choice;
}

FText UMainDisplay::GetCabinetPrice() const
{
	//return CabinetPrice;
	return MainComponents[1].Price;
}

FText UMainDisplay::GetAccentChoice() const
{
	//return AccentChoice;
	return MainComponents[0].Choice;
}

FText UMainDisplay::GetAccentPrice() const
{
	//AccentPrice
	return MainComponents[0].Price;
}

FText UMainDisplay::GetScreenChoice() const
{
	//return ScreenChoice;
	return MainComponents[2].Choice;
}
FText UMainDisplay::GetScreenPrice() const
{
	//return ScreenPrice;
	return MainComponents[2].Price;
}

///////////////////////////////////////////////////////////////////////////
void UMainDisplay::SetTotalPrice(FText TTotalPrice)	//Setter 1
{
	TotalPrice = TTotalPrice;
}
FText UMainDisplay::GetTotalPrice() const	//Getter 1
{
	return TotalPrice;
}
///////////////////////////////////////////////////////////////////////////
void UMainDisplay::SetDescription(const FText DDescription)	//Setter 2
{
	Description = DDescription;
}
FText UMainDisplay::GetDescription() const	//Getter 2
{
	return Description;
}
///////////////////////////////////////////////////////////////////////////
void UMainDisplay::SetBasePrice(FText CComponentPrice)	//Setter 3
{
	BasePrice = CComponentPrice;
}
FText UMainDisplay::GetBasePrice() const	//Getter 3
{
	return BasePrice;
}
///////////////////////////////////////////////////////////////////////////
void UMainDisplay::SetCameraName(FText CCameraName)	//Setter 4
{
	CameraName = CCameraName;
}
FText UMainDisplay::GetCameraName() const	//Getter 4
{
	return CameraName;
}
///////////////////////////////////////////////////////////////////////////

USoundBase * UMainDisplay::GetClickAux() const
{
	return ClickAudio;
}

USoundBase * UMainDisplay::GetFailClickAux() const
{
	return FailClickAudio;
}

void UMainDisplay::QuitGame()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());
	if (PlayerController) {
		PlayerController->ConsoleCommand(TEXT("Quit"));
	}
}

void UMainDisplay::CameraNextEvent()
{
	CameraNext_Dispatcher.Broadcast();
}

void UMainDisplay::CameraPreviousEvent()
{
	CameraPrevious_Dispatcher.Broadcast();
}

void UMainDisplay::PlayTrackOne()
{
	if (LogicReference) {
		LogicReference->PlayTheAudio(0);
	}
}

void UMainDisplay::PlayTrackTwo()
{
	if (LogicReference) {
		LogicReference->PlayTheAudio(1);
	}
}

void UMainDisplay::PlayTrackThree()
{
	if (LogicReference) {
		LogicReference->PlayTheAudio(2);
	}
}
