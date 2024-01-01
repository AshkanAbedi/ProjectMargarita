// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objects/BaseInteractable.h"
#include "States/ItemNames.h"
#include "States/DoorTypes.h"
#include "Doors.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class UTimelineComponent;
class UCurveFloat;
class UAudioComponent;
class USoundCue;
class APlayerCharacter;

UCLASS()
class THESEVENTHPROOF_API ADoors : public ABaseInteractable
{
	GENERATED_BODY()

public:
	ADoors();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components") TObjectPtr<USceneComponent> SceneComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components") TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Components") TObjectPtr<UTimelineComponent> TimelineComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components") TObjectPtr<UCurveFloat> TogglingCurve;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Components") TObjectPtr<UAudioComponent> AudioComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components") TObjectPtr<USoundCue> OpeningSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components") TObjectPtr<USoundCue> ClosingSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components") TObjectPtr<USoundCue> LockedSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components") TObjectPtr<USoundCue> UnlockingSound;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Components") TObjectPtr<APlayerCharacter> PlayerCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components") EDoorTypes DoorType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components") bool bIsLocked;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components") EItemNames RequiredItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (MultiLine = true)) FText LockMessage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components") float MessageDuration;
	friend class APlayerCharacter;
	
	virtual void Interact_Implementation() override;
	virtual void BeginPlay() override;
	UFUNCTION() void DoorToggling(const float Output) const;
	UFUNCTION() void TimelineFinished();

private:
	bool bIsOpen = false;
	bool bIsToggling = false;
	
};
