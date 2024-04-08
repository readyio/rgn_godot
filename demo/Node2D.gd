extends Node2D

func _ready():
	var configureData = {
		appId = "io.getready.rgntest",
		apiKey = "",
		environmentTarget = RGNEnvironmentTarget.DEVELOPMENT()
	}
	RGNCore.bindAuthChangeCallback(onAuthChangeEvent)
	RGNCore.initialize(self, configureData)

func _process(delta):
	RGNCore.update()
	
func _input(event):
	if event is InputEventKey:
		if (event.is_pressed()):
			match event.keycode:
				KEY_1:
					RGNCore.signIn(func(isLoggedIn):
						print("[signIn], isLoggedIn: " + str(isLoggedIn))
					)
					pass
				KEY_2:
					CurrencyModule.getRGNCoinEconomyAsync(
						func(result):
							print("[getRGNCoinEconomyAsync]: success, result: " + str(result)),
						func(code, message):
							print("[getRGNCoinEconomyAsync]: error, code: " + str(code) + ", message: " + message)
					)
					pass

func onAuthChangeEvent(isLoggedIn):
	print("[onAuthChangeEvent], isLoggedIn: " + str(isLoggedIn))
