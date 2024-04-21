// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DisplayContent.h"
#include "Blueprint/UserWidget.h"
#include "MainDisplay.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCameraNextSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCameraPreviousSignature);

UCLASS()
class SPEAKER_SHOWCASE_API UMainDisplay : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UMainDisplay(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category="MDisplay++")
	FCameraNextSignature CameraNext_Dispatcher;
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "MDisplay++")
	FCameraPreviousSignature CameraPrevious_Dispatcher;

	/*
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "MainDisplay++")
	struct FDisplayContent DisplayInfo;*/
	virtual bool Initialize() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MainDisplay++")
	void InitializeMainDisplayClass(class ALogic* LogicRef);

	UFUNCTION(BlueprintCallable, Category = "MDisplay++")
	void PlayButtonAudio(class USoundBase* ButtonAudio);

	//Getters
	UFUNCTION()
	class USoundBase* GetClickAux() const;
	UFUNCTION()
	class USoundBase* GetFailClickAux() const;

	UPROPERTY(BlueprintReadWrite, Category = "MainDisplay++")
	class ALogic* LogicReference;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "MainDisplay++")
	TArray<FDisplayContent> MainComponents;

	UFUNCTION()
	void SetCameraName(FText CCameraName);
	UFUNCTION()
	void SetTotalPrice(FText TTotalPrice);
	UFUNCTION()
	void SetBasePrice(FText CComponentPrice);
	UFUNCTION()
	void SetDescription(const FText DDescription);

protected:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* NextButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* PreviousButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ExitButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* TrackOneButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* TrackTwoButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* TrackThreeButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UTextBlock* BasePriceText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* SpeakerChoiceText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* SpeakerPriceText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* CabinetChoiceText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* CabinetPriceText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* AccentChoiceText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* AccentPriceText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* ScreenChoiceText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* ScreenPriceText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* TotalPriceText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* DescriptionText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* AwaitDataText;
	/*
	UPROPERTY(BlueprintReadWrite, Category="MainDisplay++")
	FText AccentChoice;
	UPROPERTY(BlueprintReadWrite, Category = "MainDisplay++")
	FText AccentPrice;
	UPROPERTY(BlueprintReadWrite, Category = "MainDisplay++")
	FText CabinetChoice;
	UPROPERTY(BlueprintReadWrite, Category = "MainDisplay++")
	FText CabinetPrice;
	UPROPERTY(BlueprintReadWrite, Category = "MainDisplay++")
	FText ScreenChoice;
	UPROPERTY(BlueprintReadWrite, Category = "MainDisplay++")
	FText ScreenPrice;
	UPROPERTY(BlueprintReadWrite, Category = "MainDisplay++")
	FText SpeakerChoice;
	UPROPERTY(BlueprintReadWrite, Category = "MainDisplay++")
	FText SpeakerPrice;*/
	UPROPERTY(BlueprintReadWrite, Category = "MainDisplay++")
	FText TotalPrice;
	UPROPERTY(BlueprintReadWrite, Category = "MainDisplay++")
	FText Description;
	UPROPERTY(BlueprintReadWrite, Category = "MainDisplay++")
	FText BasePrice;
	UPROPERTY(BlueprintReadWrite, Category = "MainDisplay++")
	FText CameraName;

	UPROPERTY(EditDefaultsOnly, Category = "Audio MDisplay++")
	class USoundBase* ClickAudio;
	UPROPERTY(EditDefaultsOnly, Category = "Audio MDisplay++")
	class USoundBase* FailClickAudio;

	UFUNCTION()
	FText GetSpeakerChoice() const;
	UFUNCTION()
	FText GetSpeakerPrice() const;
	UFUNCTION()
	FText GetCabinetChoice() const;
	UFUNCTION()
	FText GetCabinetPrice() const;
	UFUNCTION()
	FText GetAccentChoice() const;
	UFUNCTION()
	FText GetAccentPrice() const;
	UFUNCTION()
	FText GetScreenChoice() const;
	UFUNCTION()
	FText GetScreenPrice() const;
	UFUNCTION()
	FText GetTotalPrice() const;
	UFUNCTION()
	FText GetDescription() const;
	UFUNCTION()
	FText GetBasePrice() const;
	UFUNCTION()
	FText GetCameraName() const;

	UFUNCTION()
	void QuitGame();
	UFUNCTION()
	void CameraNextEvent();
	UFUNCTION()
	void CameraPreviousEvent();
	UFUNCTION()
	void PlayTrackOne();
	UFUNCTION()
	void PlayTrackTwo();
	UFUNCTION()
	void PlayTrackThree();
};
