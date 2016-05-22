#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "rice/Class.hpp"
#include "rice/Module.hpp"

#include "oni.h"
#include "launcher.h"

using namespace Rice;

extern "C"

void Init_Oni()
{
	Module rb_mOni = define_module("Oni");
	
	
	Data_Type<Launcher> rb_cWindow = define_class_under<Launcher>(rb_mOni, "Window");
	
	rb_cWindow
		.define_constructor(Constructor<Launcher>())
		.define_method("show", &Launcher::show);
}


// VALUE klass = rb_define_class_under(outer, "Window", rb_cObject);
