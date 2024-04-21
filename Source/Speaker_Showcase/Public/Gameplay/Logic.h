// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpeakerInfo.h"
#include "LogicIntel.h"
#include "DisplayContent.h"
#include "GameFramework/Actor.h"
#include "Logic.generated.h"

UCLASS()
class SPEAKER_SHOWCASE_API ALogic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALogic();

protected:

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Logic++")
	class UAudioComponent* SoundAudio;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Logic++")
	TArray<FLogicIntel> Intel;
	//<Speaker Variable>
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	int32 BasePrice = 24000;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	int32 AccentIndex=0;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	int32 AccentIndexMax=5;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	int32 AccentPrice;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	FText AccentSD;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	FText AccentLD;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	int32 CabinetIndex=0;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	int32 CabinetIndexMax=5;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	int32 CabinetPrice;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	FText CabinetSD;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	FText CabinetLD;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	int32 ScreenIndex=0;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	int32 ScreenIndexMax=5;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	int32 ScreenPrice;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	FText ScreenSD;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	FText ScreenLD;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	int32 SpeakerIndex=0;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	int32 SpeakerIndexMax=4;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	int32 SpeakerPrice;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	FText SpeakerSD;
	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	FText SpeakerLD;
	//</Speaker Variable>
	//<Data Table>
/*	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Logic++")
	class UDataTable* AccentInfo_Table;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Logic++")
	class UDataTable* CabinetInfo_Table;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Logic++")
	class UDataTable* ScreenInfo_Table;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Logic++")
	class UDataTable* SpeakerInfo_Table;*/
	//</Data Table>

	//<Component Meshes Mats>
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Logic++ Materials")
	TArray<class UMaterialInterface*> FootsMaterial;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Logic++ Materials")
	TArray<class UMaterialInterface*> CabinetMaterial;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Logic++ Materials")
	TArray<class UMaterialInterface*> WoofersMaterial;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Logic++ Materials")
	TArray<class UMaterialInterface*> TweakersMaterial;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Logic++ Materials")
	TArray<FVector> ScreenColours;
	//</Component Meshes Mats>

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Logic++")
	TArray<USoundBase*> AudioTracks;

	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	TArray<class ASpeaker*> SpeakerReference;

	UPROPERTY(BlueprintReadWrite, Category = "Logic++")
	class UMainDisplay* MainDisplayReference;
	//<Utility>
	UFUNCTION(BlueprintPure, Category = "Logic++")
	FText FormatThePrice(int32 PriceInCent);
	UFUNCTION(BlueprintCallable, Category="Logic++")
	int32& LoopComponentIndex(UPARAM(ref)int32& CompIndex, int32 CompIndexMax);
	//</Utility>

	UFUNCTION(BlueprintPure, Category = "Logic++")
	FText TotalPrice();
	UFUNCTION(BlueprintPure, Category = "Logic++")
	FText ComponentPrice(int32 CompPrice);
	UFUNCTION(BlueprintPure, Category = "Logic++")
	FText ComponentDescription() const;

	UFUNCTION(BlueprintCallable, Category = "Logic++")
	void UpdateComponent(int32 Index, UPARAM(ref)FText& SD, UPARAM(ref)FText& LD, UPARAM(ref)int32& P, UPARAM(ref)UDataTable* &ComponentDT);

	UFUNCTION(BlueprintCallable, Category = "Logic++")
	void FinalDataToWidget();

	//<Set Materials>
	UFUNCTION(BlueprintCallable, Category = "Logic++")
	void SetCabinetMaterial(class UMaterialInterface* ApplyMat);
	UFUNCTION(BlueprintCallable, Category = "Logic++")
	void SetScreenColours(FVector Col);
	UFUNCTION(BlueprintCallable, Category = "Logic++")
	void SetAccentsMaterial(class UMaterialInterface* AccentMat, class UMaterialInterface* FootMat);
	UFUNCTION(BlueprintCallable, Category="Logic++")
	void SetSpeakersMaterial(class UMaterialInterface* ApplyWoof, class UMaterialInterface* ApplyTweater);
	//</Set Materials>

public:	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Logic++")
	void InitializeLogicClass(const TArray<class ASpeaker*> &SpeakerArray, class UMainDisplay* MainDisplayRef);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Logic++")
	void Accent();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Logic++")
	void Cabinet();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category ="Logic++")
	void Screen();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Logic++")
	void Speaker();

	UFUNCTION(BlueprintCallable, Category="Logic++")
	void PlayTheAudio(int32 Track);

	UFUNCTION(BlueprintCallable, Category = "Logic++")
	void StartingDataToWidget();
	UFUNCTION(BlueprintCallable, Category = "Logic++")
	void SendPriceDataToWidget();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Logic++")
	bool CompareID(FDisplayContent DContent, FLogicIntel LIntel);
	UFUNCTION(BlueprintCallable, Category = "Logic++")
	void SendChoiceDataToWidget();

	UFUNCTION()
	void Dummy() const;
};
