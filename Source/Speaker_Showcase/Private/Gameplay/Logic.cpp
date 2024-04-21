// Fill out your copyright notice in the Description page of Project Settings.


#include "Logic.h"
#include "Components/AudioComponent.h"
#include "Speaker.h"
#include "MainDisplay.h"
#include "Engine/DataTable.h"
#include "SpeakerInfo.h"
#include "LogicIntel.h"
#include "DisplayContent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ALogic::ALogic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SoundAudio = CreateDefaultSubobject<UAudioComponent>("SoundAudio");
	SoundAudio->SetupAttachment(RootComponent);

}

void ALogic::InitializeLogicClass_Implementation(const TArray<class ASpeaker*> &SpeakerArray, class UMainDisplay* MainDisplayRef)
{
	//Overridden in BP
	SpeakerReference = SpeakerArray;
	MainDisplayReference = MainDisplayRef;
}

void ALogic::FinalDataToWidget()
{
	MainDisplayReference->SetTotalPrice(TotalPrice());
	SendPriceDataToWidget();
	SendChoiceDataToWidget();
	MainDisplayReference->SetDescription(ComponentDescription());
}

void ALogic::SetCabinetMaterial(UMaterialInterface * ApplyMat)
{
	int Length = SpeakerReference.Num();
	for (int i = 0; i < Length; i++) {
		SpeakerReference[i]->GetCabinet()->SetMaterial(0, ApplyMat);
	}
}

void ALogic::SetScreenColours(FVector Col)
{
	int Length = SpeakerReference.Num();
	for (int i = 0; i < Length; i++) {
		SpeakerReference[i]->GetScreen()->SetVectorParameterValueOnMaterials(TEXT("Color"), Col);
	}
}

void ALogic::SetAccentsMaterial(UMaterialInterface * AccentMat, UMaterialInterface * FootMat)
{
	int Length = SpeakerReference.Num();
	for (int i = 0; i < Length; i++) {
		int Len = SpeakerReference[i]->AccentComponent.Num();
		int Leng = SpeakerReference[i]->MeshComponent.Num();
		for (int j = 0; j < Len; j++)
		{
			SpeakerReference[i]->AccentComponent[j]->SetMaterial(0, AccentMat);
		}
		for (int k = 0; k < Leng; k++) {
			SpeakerReference[i]->MeshComponent[k]->SetMaterial(0, FootMat);
		}
	}
}

void ALogic::SetSpeakersMaterial(UMaterialInterface * ApplyWoof, UMaterialInterface * ApplyTweater)
{
	int length = SpeakerReference.Num();
	for (int i = 0; i < length; i++) {
		UStaticMeshComponent* Temp;
		SpeakerReference[i]->GetSpeaker(Temp)->SetMaterial(0, ApplyTweater);
		Temp->SetMaterial(0, ApplyWoof);
	}
}

void ALogic::PlayTheAudio(int32 Track)
{
	SoundAudio->Stop();
	USoundBase* AC = AudioTracks[Track];
	SoundAudio->SetSound(AC);
	SoundAudio->Play();
}

FText ALogic::FormatThePrice(int32 PriceInCent)
{
	return FText::AsCurrencyBase(PriceInCent, FString(TEXT("RM")));
}

int32& ALogic::LoopComponentIndex(UPARAM(ref)int32& CompIndex, int32 CompIndexMax)
{
	CompIndex++;
	CompIndex = CompIndex % CompIndexMax;
	return CompIndex;
}

FText ALogic::TotalPrice()
{
	//AccentPrice CabinetPrice ScreenPrice SpeakerPrice
	int32 TotalPrice;
	TotalPrice = BasePrice + Intel[0].Price +Intel[1].Price + Intel[2].Price + Intel[3].Price;
	return FormatThePrice(TotalPrice);
}

FText ALogic::ComponentPrice(int32 CompPrice)
{
	return FormatThePrice(CompPrice);
}

FText ALogic::ComponentDescription() const
{	//SpeakerLD CabinetLD
	FString SpLD = Intel[3].LongDesc.ToString();
	FString A = FString(SpLD + " Mounted In");
	FString CabLD = Intel[1].LongDesc.ToString();
	FString B = FString(A + " " + CabLD);
	FString C = FString(B + " " + "Cabinet and");
	//AccentLD
	FString AccLD = Intel[0].LongDesc.ToString();
	FString D = FString(C + " " + AccLD);
	return FText(FText::FromString(D));
}

void ALogic::UpdateComponent(int32 Index, UPARAM(ref)FText & SD, UPARAM(ref)FText & LD, UPARAM(ref)int32& P, UPARAM(ref)UDataTable* &ComponentDT)
{
	FString IntStr = FString::FromInt(Index);
	FName RowName = FName(*IntStr);
	FSpeakerInfo* ComponentDataTable = ComponentDT->FindRow<FSpeakerInfo>(RowName, "");
	SD = ComponentDataTable->ShortDescription;
	LD = ComponentDataTable->LongDescription;
	P = ComponentDataTable->Price;
	FinalDataToWidget();
}

void ALogic::Accent_Implementation()
{
	//AccentIndex, AccentIndexMax
	int32 condition = LoopComponentIndex(Intel[0].Index, Intel[0].IndexMax);
	SetAccentsMaterial(CabinetMaterial[condition], FootsMaterial[condition]);
	//AccentSD, AccentPrice, AccentLD, AccentInfo_Table
	UpdateComponent(condition, Intel[0].ShortDesc, Intel[0].LongDesc, Intel[0].Price, Intel[0].InfoTable);
}

void ALogic::Cabinet_Implementation()
{	//CabinetIndex CabinetIndexMax
	int32 condition = LoopComponentIndex(Intel[1].Index, Intel[1].IndexMax);
	//CabinetSD CabinetLD CabinetPrice CabinetInfo_Table
	SetCabinetMaterial(CabinetMaterial[condition]);
	UpdateComponent(condition, Intel[1].ShortDesc, Intel[1].LongDesc, Intel[1].Price, Intel[1].InfoTable);
}

void ALogic::Screen_Implementation()
{	//ScreenIndex ScreenIndexMax
	int32 condition = LoopComponentIndex(Intel[2].Index, Intel[2].IndexMax);
	SetScreenColours(ScreenColours[condition]);
	//ScreenSD ScreenLD ScreenPrice ScreenInfo_Table
	UpdateComponent(condition, Intel[2].ShortDesc, Intel[2].LongDesc, Intel[2].Price, Intel[2].InfoTable);
}

void ALogic::Speaker_Implementation()
{	//SpeakerIndex SpeakerIndexMax
	int32 condition = LoopComponentIndex(Intel[3].Index, Intel[3].IndexMax);
	SetSpeakersMaterial(WoofersMaterial[condition], TweakersMaterial[condition]);
	//SpeakerSD SpeakerLD SpeakerPrice SpeakerInfo_Table
	UpdateComponent(condition, Intel[3].ShortDesc, Intel[3].LongDesc, Intel[3].Price, Intel[3].InfoTable);
}

void ALogic::StartingDataToWidget()
{
	int Length = Intel.Num();
	for (int i = 0; i < Length; i++) {
		UpdateComponent(0, Intel[i].ShortDesc, Intel[i].LongDesc, Intel[i].Price, Intel[i].InfoTable);
	}
}

void ALogic::SendPriceDataToWidget()
{
	int IntelLeng = Intel.Num();
	int leng = MainDisplayReference->MainComponents.Num();
	for (int i = 0; i < IntelLeng; i++) {
		for (int j = 0; j < leng; j++) {
			if (CompareID(MainDisplayReference->MainComponents[j], Intel[i])) {
				MainDisplayReference->MainComponents[j].Price = ComponentPrice(Intel[i].Price);
			}
		}
	}
	MainDisplayReference->SetBasePrice(ComponentPrice(BasePrice));
}

bool ALogic::CompareID(FDisplayContent DContent, FLogicIntel LIntel)
{
	bool temp = DContent.ComponentId == LIntel.ComponentId;
	return temp;
}

void ALogic::SendChoiceDataToWidget()
{
	int IntelLeng = Intel.Num();
	int Length = MainDisplayReference->MainComponents.Num();
	for (int i = 0; i < IntelLeng; i++) {
		for (int j = 0; j < Length; j++) {
			if (CompareID(MainDisplayReference->MainComponents[j], Intel[i])) {
				MainDisplayReference->MainComponents[j].Choice = Intel[i].ShortDesc;
			}
		}
	}
}

void ALogic::Dummy() const
{
	UE_LOG(LogTemp, Warning, TEXT("From Logic++ Called from Widget"));
}
