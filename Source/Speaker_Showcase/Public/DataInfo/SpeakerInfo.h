// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "SpeakerInfo.generated.h"
/**
 * 
 */
USTRUCT(Blueprintable)
struct SPEAKER_SHOWCASE_API FSpeakerInfo : public FTableRowBase
{
	GENERATED_BODY()

protected:

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SpeakerInfo++")
	FText LongDescription;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SpeakerInfo++")
	FText ShortDescription;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SpeakerInfo++")
	int32 Price;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "SpeakerInfo++")
	UDataTable* ComponentDataTable;
};
