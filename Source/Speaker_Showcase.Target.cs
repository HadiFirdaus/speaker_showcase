// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Speaker_ShowcaseTarget : TargetRules
{
	public Speaker_ShowcaseTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Speaker_Showcase" } );
	}
}
