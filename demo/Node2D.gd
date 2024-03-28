extends Node2D

func _ready():
	var configureData = {
		appId = "io.getready.rgntest",
		apiKey = "",
		environmentTarget = RGNEnvironmentTarget.DEVELOPMENT()
	}
	RGNCore.initialize(configureData)

func _process(delta):
	RGNCore.update()
