require File.expand_path('./oni', File.absolute_path(File.dirname(__FILE__)))


# TODO: rename things so this project doesn't have symbol collision with the other package I named "Oni", from which this project's template derives.
	
# TODO: wrap functions to get window dimensions
# TODO: consider marking all drawing methods as private from Ruby-land

class Window < Oni::Window
	def initialize
		super(self) # pass Ruby instance to C++ land for callbacks, etc
		
		puts "ruby: Window#initialize"
		
		@p = [0,0]
		
		@p_history = Array.new
		@trail_dt = 1
		
		
		@font = Oni::TrueTypeFont.new
		load_status = @font.load("DejaVu Sans", 20)
		puts "Font loaded?: #{load_status}"
	end
	
	def setup
		super()
	end
	
	def update
		# super()
		
		@tick ||= 0
		@tick += 1
		if @tick == @trail_dt
			@tick = 0
			
			@p_history << @p
		end
		
		trail_length = 20*3*2
		# if @tick == 30
		# 	@p_history.shift
		# end
		
		if @p_history.length > trail_length
			i = [0, @p_history.length - trail_length - 1].max
			@p_history.shift(i)
		end
		
		# p @p_history
	end
	
	def draw
		# super()
		
		
		z = 1
		
		ofDrawBitmapString("hello again from ruby!", 300, 350, z);
		
		# ofSetColor(255,0,0, 255) # rgba
		# ofDrawCircle(*@p,z, 20)
		
		@p_history.reverse_each.each_with_index do |p, i|
			next unless i % 3 == 0
			
			x,y = p
			ofSetColor(255,0,0, 255-i*10) # rgba
			
			r = 20-i/2
			r = 0 if r < 0
			ofDrawCircle(x,y,z, r)
		end
		
		
		ofSetColor(255,255,255, 255) # rgba
		x,y = @p_history.last
		@font.draw_string("TrueTypeFont Test!", x, y)
	end
	
	def mouse_moved(x,y)
		super(x,y)
		
		@p = [x,y]
	end
	
	def mouse_pressed(x,y, button)
		super(x,y, button)
		
		exit() if button == 4
		# TODO: set button codes as constants?
	end
	
	def mouse_released(x,y, button)
		super(x,y, button)
	end
	
	def mouse_dragged(x,y, button)
		super(x,y, button)
	end
end

x = Window.new
x.show
