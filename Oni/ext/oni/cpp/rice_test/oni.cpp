#include "rice/Class.hpp"
#include "rice/Module.hpp"
#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"

#include "window.h"

using namespace Rice;

extern "C"

void Init_test()
{
	Module rb_mOni = define_module("Oni");
	
	
	
	Data_Type<Window> rb_cWindow = define_class_under<Window>(rb_mOni, "Window");
	
	
	rb_cWindow
		.define_constructor(Constructor<Window>())
		.define_method("open", &Test::open);
}


// VALUE klass = rb_define_class_under(outer, "Window", rb_cObject);
