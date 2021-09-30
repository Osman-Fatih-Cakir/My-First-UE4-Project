// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultItem.h"
#include "Engine/EngineTypes.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/Object.h"
//#include "Components/PrimitiveComponent.h"

// Constructor
ADefaultItem::ADefaultItem()
{
	PrimaryActorTick.bCanEverTick = true;

	this->ItemType = 0;
	this->ItemName = "Default";
	this->spawnProb = 1.f;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));

	// TriggerBox
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	TriggerBox->InitBoxExtent(FVector(1, 1, 1));
	TriggerBox->SetCollisionProfileName(TEXT("Trigger"));
	TriggerBox->SetupAttachment(RootComponent);

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ADefaultItem::OnOverlapBegin);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ADefaultItem::OnOverlapEnd);

}

void ADefaultItem::BeginPlay()
{
	QuatRot = FQuat(rotation);
	
}

void ADefaultItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Constantly rotation
	AddActorLocalRotation(QuatRot, false, 0, ETeleportType::None);
}

void ADefaultItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
	}
}

void ADefaultItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap End"));
		}
	}
}

