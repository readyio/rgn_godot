extends TextEdit

@onready var regex = RegEx.new()

func _ready():
    regex.compile("[0-9]")
    connect("text_changed", _text_changed)

func _text_changed():
    var final_text = ""
    var matches = regex.search_all(text)
    if matches:
        for i in range(0, matches.size()):
            final_text += matches[i].get_string()
    text = final_text
    set_caret_column(text.length())