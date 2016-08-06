require './oni/oni'
	
class Window < Oni::Window
	def initialize
		super(self) # pass Ruby instance to C++ land for callbacks, etc
		
		puts "ruby: Window#initialize"
		
		@p = [0,0]
		
		@p_history = Array.new
		@trail_dt = 1
	end
	
	def setup
		puts "ruby: Window#setup"
	end
	
	def update
		# puts "ruby: Window#update"
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
		puts "ruby: Window#draw"
		z = 1
		
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
	end
	
	def mouse_moved(x,y)
		p [x,y]
		
		@p = [x,y]
	end
	
	def mouse_pressed(x,y, button)
		p [:pressed, x,y, button]
		
		exit() if button == 4
		# TODO: set button codes as constants?
	end
	
	def mouse_released(x,y, button)
		p [:released, x,y, button]
	end
	
	def mouse_dragged(x,y, button)
		p [:dragged, x,y, button]
	end
	
	
	
	private
	
	def exit(status_code=0)
		super(status_code)
	end
end

x = Window.new
x.show
