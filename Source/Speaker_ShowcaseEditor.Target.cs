// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Speaker_ShowcaseEditorTarget : TargetRules
{
	public Speaker_ShowcaseEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Speaker_Showcase" } );
	}
}
