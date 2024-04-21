// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "CameraNameInfo.generated.h"
/**
 * 
 */
USTRUCT(Blueprintable)
struct SPEAKER_SHOWCASE_API FCameraNameInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "CameraNameInfo++")
	FText CameraName;
};
