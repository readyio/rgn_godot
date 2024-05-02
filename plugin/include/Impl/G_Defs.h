#ifdef GODOT3
    #include <Godot.hpp>
    #include <Node.hpp>
    #include <String.hpp>
    #include <Array.hpp>
    #include <Dictionary.hpp>
    #include <Variant.hpp>
    #include <String.hpp>
    #include <Ref.hpp>
    #include <FuncRef.hpp>
    #define REG_GCLASS(CLASS_NAME, CLASS_TYPE) GODOT_CLASS(CLASS_NAME, CLASS_TYPE)
    #define REG_GCLASS_METHODS_HEADER() static void _register_methods()
    #define REG_GCLASS_METHODS_SOURCE(CLASS) void CLASS::_register_methods()
    #define GCLASS_METHOD_SIGNATURE(METHOD, ...) METHOD
    #define BIND_GCLASS_METHOD(CLASS_METHOD, SIGNATURE) godot::register_method(SIGNATURE, &CLASS_METHOD)
    #define BIND_GCLASS_METHOD_DEFVAL(CLASS_METHOD, SIGNATURE, ...) godot::register_method(SIGNATURE, &CLASS_METHOD)
    #define GCALLBACK godot::Ref<godot::FuncRef>
    #define GCALLBACK_DEFVAL nullptr
    #define EXECUTE_GCALLBACK_DEFVAL(CALLBACK, ARGS) const_cast<godot::FuncRef*>(CALLBACK.ptr())->call_funcv(ARGS);
#else
    #include <godot_cpp/variant/string.hpp>
    #include <godot_cpp/variant/array.hpp>
    #include <godot_cpp/variant/dictionary.hpp>
    #include <godot_cpp/variant/variant.hpp>
    #include <godot_cpp/variant/callable.hpp>
    #include <godot_cpp/core/class_db.hpp>
    #include <godot_cpp/classes/ref.hpp>
    #include <godot_cpp/classes/node.hpp>
    #define REG_GCLASS(CLASS_NAME, CLASS_TYPE) GDCLASS(CLASS_NAME, CLASS_TYPE)
    #define REG_GCLASS_METHODS_HEADER() static void _bind_methods()
    #define REG_GCLASS_METHODS_SOURCE(CLASS) void CLASS::_bind_methods()
    #define GCLASS_METHOD_SIGNATURE(METHOD, ...) METHOD, __VA_ARGS__
    #define BIND_GCLASS_METHOD(CLASS_METHOD, SIGNATURE) godot::ClassDB::bind_method(godot::D_METHOD(SIGNATURE), &CLASS_METHOD)
    #define BIND_GCLASS_METHOD_DEFVAL(CLASS_METHOD, SIGNATURE, ...) godot::ClassDB::bind_method(godot::D_METHOD(SIGNATURE), &CLASS_METHOD, __VA_ARGS__)
    #define GCALLBACK godot::Callable
    #define GCALLBACK_DEFVAL GCALLBACK()
    #define EXECUTE_GCALLBACK_DEFVAL(CALLBACK, ARGS) CALLBACK.callv(ARGS)
#endif