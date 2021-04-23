// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Perception/AIPerceptionTypes.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyAI.generated.h"


UCLASS()
class FIRSTUE4PROJECT_API AEnemyAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveToWaypoints();

	UFUNCTION(BlueprintCallable)
	void ChangeSeePlayerState();

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	int CurrentWaypoint;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	int MaxWaypoint = 61;

	AActor* Player;
	TArray<AActor*> Waypoints;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SeePlayer = false;
};