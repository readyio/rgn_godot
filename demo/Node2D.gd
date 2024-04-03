extends Node2D

func _ready():
	var configureData = {
		appId = "io.getready.rgntest",
		apiKey = "",
		environmentTarget = RGNEnvironmentTarget.DEVELOPMENT()
	}
	RGNCore.initialize(self, configureData)

func _process(delta):
	RGNCore.update()
	
func _input(event):
	if event is InputEventKey:
		if (event.is_pressed() && event.keycode == KEY_SPACE):
			RGNCore.signIn();
