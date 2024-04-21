// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DisplayContent.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct SPEAKER_SHOWCASE_API FDisplayContent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName ComponentId;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Choice;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Price;
};
