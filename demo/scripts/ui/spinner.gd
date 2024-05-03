extends Node

var tween : Tween

func _ready():
	tween = Tween.new()
	add_child(tween)
	tween.repeat = true
	tween.interpolate_property(self, "rect_rotation", 0, 360, 1, Tween.TRANS_LINEAR, Tween.EASE_IN_OUT)
	tween.start()
