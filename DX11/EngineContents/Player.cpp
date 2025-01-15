#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/DefaultSceneComponent.h>

APlayer::APlayer()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Renderer = CreateDefaultSubObject<MyCustomRenderer>();
	Renderer->SetupAttachment(RootComponent);
	// Renderer->SetSprite("Test.png", 2);
	// Renderer->SetAutoScale(true);
	// Renderer->SetAutoScaleRatio(5.0f);
	Renderer->SetScale3D({ 200.0f, 200.0f, 200.0f });
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	APawn::BeginPlay();
}

void APlayer::Tick(float _DeltaTime)
{
	APawn::Tick(_DeltaTime);
	AddActorRotation(FVector(0.0f,0.0f, 10.0f,1.0f) *_DeltaTime);
}

