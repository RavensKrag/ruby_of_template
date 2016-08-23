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
		
		# NOTE: background color should be set from C++ level, because C++ level code executes first. May consider flipping the order, or even defining TWO callbacks to Ruby.
		# ofBackground(171, 160, 228,   255) # rgba
		
		z = 1
		
		
		start = [20, 20]
		row_spacing = 15
		
		[
			"mouse: #{@p.inspect}",
			"dt: #{ofGetLastFrameTime()}",
			"fps: #{ofGetFrameRate()}"
		].each_with_index do |string, i|
			x,y = start
			y += i*row_spacing
			
			ofDrawBitmapString(string, x,y,z)
		end
		
		
		
		
		
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
		
		
		ofSetColor(0, 141, 240, 255) # rgba
		x,y = @p
			# not sure why, but need to get variables again?
			# if you don't, the text trails behind the desired position by a couple seconds.
		@font.draw_string("TrueTypeFont Test!", x, y)
	end
	
	def on_exit
		super()
	end
	
	def mouse_moved(x,y)
		@p = [x,y]
	end
	
	def mouse_pressed(x,y, button)
		super(x,y, button)
		
		ofExit() if button == 8
		# different window systems return different numbers
		# for the 'forward' mouse button:
			# GLFW: 4
			# Glut: 8
		# TODO: set button codes as constants?
		
		
		
		if button == 7
			# p window_size()
			p Oni::Point.new(200, 200, 0)
			self.set_window_position(200, 200) 
			
			
			
			@cursor_visible = true if @cursor_visible.nil?
			p @cursor_visible
			if @cursor_visible
				hide_cursor
			else
				show_cursor
			end
				
			@cursor_visible = !@cursor_visible
		end
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
