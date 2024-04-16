extends Node

var tween : Tween

func _ready():
	tween = create_tween()
	tween.set_loops(0)
	tween.tween_property(self, "rotation", 360, 1).as_relative()
