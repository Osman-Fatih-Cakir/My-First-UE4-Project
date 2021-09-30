// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class FIRSTUE4PROJECT_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Increases score
	UFUNCTION(BlueprintCallable, Category = "Score Functions")
	void AddScore(int value);

	// Decrease score
	UFUNCTION(BlueprintCallable, Category = "Score Functions")
	void DeleteScore(int value);

	// Resets score
	UFUNCTION(BlueprintCallable, Category = "Score Functions")
	void ResetScore();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void CalculateMoveForward(float value);
	void CalculateMoveRight(float value);
	void CalculateRotate(float value);

	void Move();
	void Rotate();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int score = 0;

private:
	FVector MoveDirection;
	FQuat RotationDirection;

	float MoveSpeed = 500.f;
	float RotateSpeed = 50.f;

	UPROPERTY(EditAnywhere)
	float RotateAmount = 0.f;
};
