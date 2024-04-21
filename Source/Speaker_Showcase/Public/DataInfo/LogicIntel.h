// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LogicIntel.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct SPEAKER_SHOWCASE_API FLogicIntel
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FName ComponentId;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 Index;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 IndexMax;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FText ShortDesc;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FText LongDesc;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 Price;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	class UDataTable* InfoTable;
};
