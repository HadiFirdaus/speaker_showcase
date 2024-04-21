// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "GameLevel.generated.h"
/**
 * 
 */
UCLASS()
class SPEAKER_SHOWCASE_API AGameLevel : public ALevelScriptActor
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = "Level++")
	bool IsCameraUp;
	UPROPERTY(BlueprintReadWrite, Category = "Level++")
	bool IsCameraAllowed=true;
	UPROPERTY(BlueprintReadWrite, Category = "Level++")
	int32 MaxCamera;
	UPROPERTY(BlueprintReadWrite, Category = "Level++")
	int32 NumOfCamera;
	UPROPERTY(BlueprintReadWrite, Category = "Level++")
	float CameraBlendTime=2.0f;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Level++")
	class UDataTable* CameraName_Table;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Level++")
	TArray<ACameraActor*> CameraArray;

	UPROPERTY(BlueprintReadWrite, Category = "Level++")
	TArray<class ASpeaker*> SpeakerArray;

	UPROPERTY(BlueprintReadWrite, Category = "Level++")
	UMainDisplay* MainDisplayReference;

	UPROPERTY(EditDefaultsOnly, Category = "Level++")
	TSubclassOf<UUserWidget> MainDisplayClass;
	
	UFUNCTION(BlueprintCallable, Category = "Level++")
	UMainDisplay* GetMainDisplay();

	UFUNCTION(BlueprintCallable, Category = "Level++")
	void CamNameToWidget(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Level++")
	void GoToCamera(int32 CameraInt);

	UFUNCTION(BlueprintCallable, Category = "Level++")
	void CameraTransition();

	UFUNCTION(BlueprintCallable, Category = "Level++")
	void InitializeCameraLevel(AActor* CamTarget);

	UFUNCTION()
	void CameraNextButton();
	UFUNCTION()
	void CameraPreviousButton();

	UFUNCTION()
	void Delay();

private:
	class UMainDisplay* MainDisplay;
};
