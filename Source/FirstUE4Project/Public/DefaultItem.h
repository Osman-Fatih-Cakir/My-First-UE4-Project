// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Item.h"
#include "Components/BoxComponent.h"
#include "Components/PrimitiveComponent.h"

#include "DefaultItem.generated.h"

UCLASS()
class FIRSTUE4PROJECT_API ADefaultItem : public AItem
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	ADefaultItem();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


	void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, Category = "Trigger Box")
	class UBoxComponent* TriggerBox;

	FRotator rotation = FRotator(0.f, 1.f, 0.f);
	FQuat QuatRot;
};
