// Fill out your copyright notice in the Description page of Project Settings.


#include "Speaker.h"
#include "Components/StaticMeshComponent.h"
#include "Logic.h"

// Sets default values
ASpeaker::ASpeaker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	AccentMesh = CreateDefaultSubobject<UStaticMeshComponent>("Assent");
	AccentMesh->SetupAttachment(Root);

	CabinetMesh = CreateDefaultSubobject<UStaticMeshComponent>("Cabinet");
	CabinetMesh->SetupAttachment(Root);

	FootBL_Mesh = CreateDefaultSubobject<UStaticMeshComponent>("FootBL");
	FootBL_Mesh->SetupAttachment(Root);

	FootBR_Mesh = CreateDefaultSubobject<UStaticMeshComponent>("FootBR");
	FootBR_Mesh->SetupAttachment(Root);

	FootFL_Mesh = CreateDefaultSubobject<UStaticMeshComponent>("FootFL");
	FootFL_Mesh->SetupAttachment(Root);
	
	FootFR_Mesh = CreateDefaultSubobject<UStaticMeshComponent>("FootFR");
	FootFR_Mesh->SetupAttachment(Root);

	FrameMesh = CreateDefaultSubobject<UStaticMeshComponent>("FrameMesh");
	FrameMesh->SetupAttachment(Root);

	ScreenMesh = CreateDefaultSubobject<UStaticMeshComponent>("ScreenMesh");
	ScreenMesh->SetupAttachment(FrameMesh);

	HornTweaterMesh = CreateDefaultSubobject<UStaticMeshComponent>("HornTweater");
	HornTweaterMesh->SetupAttachment(Root);

	ScrewMesh = CreateDefaultSubobject<UStaticMeshComponent>("ScrewMesh");
	ScrewMesh->SetupAttachment(Root);

	WooferMesh = CreateDefaultSubobject<UStaticMeshComponent>("WooferMesh");
	WooferMesh->SetupAttachment(Root);

	//Assign Array
	MeshComponent.Add(FootBL_Mesh);
	MeshComponent.Add(FootBR_Mesh);
	MeshComponent.Add(FootFL_Mesh);
	MeshComponent.Add(FootFR_Mesh);

	AccentComponent.Add(AccentMesh);
	AccentComponent.Add(FrameMesh);
}
 
// Called when the game starts or when spawned
void ASpeaker::BeginPlay()
{
	Super::BeginPlay();
	AccentMesh->OnClicked.AddDynamic(this, &ASpeaker::OnClickedComponent);
	CabinetMesh->OnClicked.AddDynamic(this, &ASpeaker::OnClickedCabinet);
	FootBL_Mesh->OnClicked.AddDynamic(this, &ASpeaker::OnClickedComponent);
	FootBR_Mesh->OnClicked.AddDynamic(this, &ASpeaker::OnClickedComponent);
	FootFL_Mesh->OnClicked.AddDynamic(this, &ASpeaker::OnClickedComponent);
	FootFR_Mesh->OnClicked.AddDynamic(this, &ASpeaker::OnClickedComponent);
	FrameMesh->OnClicked.AddDynamic(this, &ASpeaker::OnClickedComponent);
	ScreenMesh->OnClicked.AddDynamic(this, &ASpeaker::OnClickedScreen);
	HornTweaterMesh->OnClicked.AddDynamic(this, &ASpeaker::OnClickedHornTweater);
	ScrewMesh->OnClicked.AddDynamic(this, &ASpeaker::OnClickedComponent);
	WooferMesh->OnClicked.AddDynamic(this, &ASpeaker::OnClickedHornTweater);
}

void ASpeaker::InitializeSpeakerClass_Implementation(class ALogic* LogicRef)
{
	//Overidden in BP
}

UStaticMeshComponent * ASpeaker::GetAccents(UPARAM(ref)TArray<class UStaticMeshComponent*> &AccentsComp)
{
	int Length = AccentsComp.Num();
	for (int i = 0; i < Length; i++) {
		return AccentsComp[i];
	}
	return nullptr; //this could be wrong
}

UStaticMeshComponent * ASpeaker::GetAccentTrial()
{
	int Length = AccentComponent.Num();
	int i = 0;
	for (i; i < Length; i++) {
		return AccentComponent[i];
	}
	return AccentComponent[i];
}

UStaticMeshComponent * ASpeaker::GetFoots()
{
	int Length = MeshComponent.Num();
	int i = 0;
	for (i; i < Length; i++) {
		return MeshComponent[i];
	}
	return MeshComponent[i];
}

UStaticMeshComponent * ASpeaker::GetScreen() const
{
	return ScreenMesh;
}

UStaticMeshComponent * ASpeaker::GetCabinet() const
{
	return CabinetMesh;
}

UStaticMeshComponent * ASpeaker::GetSpeaker(UStaticMeshComponent *& Woofers)
{
	Woofers = WooferMesh;
	return HornTweaterMesh;
}

void ASpeaker::CheckActivation()
{
	if (IsActive) {
		FrameMesh->SetVisibility(true);
		ScreenMesh->SetVisibility(true);
	}
	else {
		FrameMesh->SetVisibility(false);
		ScreenMesh->SetVisibility(false);
		FrameMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		ScreenMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	}
}

void ASpeaker::OnClickedComponent(UPrimitiveComponent * TouchedComponent, FKey ButtonPressed)
{
	if (LogicReference) {
		LogicReference->Accent();
	}
}

void ASpeaker::OnClickedCabinet(UPrimitiveComponent * TouchedComponent, FKey ButtonPressed)
{
	if (LogicReference) {
		LogicReference->Cabinet();
	}
}

void ASpeaker::OnClickedScreen(UPrimitiveComponent * TouchedComponent, FKey ButtonPressed)
{
	if (LogicReference) {
		LogicReference->Screen();
	}
}

void ASpeaker::OnClickedHornTweater(UPrimitiveComponent * TouchedComponent, FKey ButtonPressed)
{
	if (LogicReference) {
		LogicReference->Speaker();
	}
}

void ASpeaker::Dumb()
{
	int length = MeshComponent.Num();
	FString ArrInt;
	for (int i = 0; i < length; i++) {
		ArrInt = MeshComponent[i]->GetName();
		UE_LOG(LogTemp, Warning, TEXT("ArrayInt Contents: %s"), *ArrInt);
	}
}