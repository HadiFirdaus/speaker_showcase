// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Speaker.generated.h"

UCLASS()
class SPEAKER_SHOWCASE_API ASpeaker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpeaker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnClickedComponent(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

	UFUNCTION()
	void OnClickedCabinet(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

	UFUNCTION()
	void OnClickedScreen(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

	UFUNCTION()
	void OnClickedHornTweater(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

	UFUNCTION(BlueprintCallable, Category = "Speaker++")
	void CheckActivation();

public:	

	UPROPERTY(BlueprintReadOnly, EditInstanceOnly, Category = "Speaker++")
	bool IsActive = true;

	UPROPERTY(BlueprintReadWrite, Category = "Speaker++")
	class ALogic* LogicReference;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Speaker++")
	TArray<class UStaticMeshComponent*> MeshComponent;
	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Speaker++")
	TArray<class UStaticMeshComponent*> AccentComponent;

	UPROPERTY(VisibleAnywhere, Category = "Speaker++")
	class USceneComponent* Root;
	//<Mesh Components>
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Speaker++")
	class UStaticMeshComponent* AccentMesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Speaker++")
	class UStaticMeshComponent* CabinetMesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Speaker++")
	class UStaticMeshComponent* FootBL_Mesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Speaker++")
	class UStaticMeshComponent* FootBR_Mesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Speaker++")
	class UStaticMeshComponent* FootFL_Mesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Speaker++")
	class UStaticMeshComponent* FootFR_Mesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Speaker++")
	class UStaticMeshComponent* FrameMesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Speaker++")
	class UStaticMeshComponent* ScreenMesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Speaker++")
	class UStaticMeshComponent* HornTweaterMesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Speaker++")
	class UStaticMeshComponent* ScrewMesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Speaker++")
	class UStaticMeshComponent* WooferMesh;
	//</Mesh Components>

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Speaker++")
	void InitializeSpeakerClass(class ALogic* LogicRef);

	UFUNCTION(BlueprintCallable, Category = "Speaker++")
	UStaticMeshComponent* GetAccents(UPARAM(ref)TArray<class UStaticMeshComponent*> &AccentsComp);

	UFUNCTION(BlueprintCallable, Category = "Speaker++")
	UStaticMeshComponent* GetFoots();

	UFUNCTION(BlueprintCallable, Category = "Speaker++")
	UStaticMeshComponent* GetScreen() const;

	UFUNCTION(BlueprintCallable, Category = "Speaker++")
	UStaticMeshComponent* GetCabinet() const;

	UFUNCTION(BlueprintCallable, Category = "Speaker++")
	UStaticMeshComponent* GetSpeaker(UStaticMeshComponent* &Woofers);

	UFUNCTION(BlueprintCallable, Category = "Speaker++")
	UStaticMeshComponent* GetAccentTrial();

	UFUNCTION()
	void Dumb();
	
	UFUNCTION()
	class AActor* GetSpeakerClass();

private:
	UPROPERTY()
	class AActor* Speakers;
};
