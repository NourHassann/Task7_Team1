import math

class TriangularWheeledRobot:
    def __init__(self, wheel_radius, wheel_distance):
        self.wheel_radius = wheel_radius
        self.wheel_distance = wheel_distance
        self.motor_pwm_values = [0, 0, 0]  # Initialize PWM values for each motor

        # Initialize position and orientation
        self.x = 0.0
        self.y = 0.0
        self.theta = 0.0

        # PID controller gains
        self.kp_x = 1.0
        self.kp_y = 1.0
        self.kp_theta = 1.0

    def update_motors(self, target_x, target_y, target_theta):
        # Calculate position error
        error_x = target_x - self.x
        error_y = target_y - self.y

        # Calculate control inputs using PID
        Vx = self.kp_x * error_x
        Vy = self.kp_y * error_y

        # Calculate orientation error
        error_theta = target_theta - self.theta

        # Ensure the orientation error is within [-pi, pi] range
        if error_theta > math.pi:
            error_theta -= 2 * math.pi
        elif error_theta < -math.pi:
            error_theta += 2 * math.pi

        # Calculate angular velocity omega using PID
        omega = self.kp_theta * error_theta

        # Update the motor PWM values based on the input velocities
        self.calculate_motor_pwm(Vx, Vy, omega)

    def calculate_motor_pwm(self, Vx, Vy, omega):
        # Calculate the linear velocity of each wheel
        wheel_velocities = [0.0, 0.0, 0.0]

        # Calculate the linear velocity of the first wheel
        wheel_velocities[0] = (Vx * math.cos(math.radians(30)) + Vy * math.sin(math.radians(30))) / self.wheel_radius

        # Calculate the linear velocity of the second wheel
        wheel_velocities[1] = (Vx * math.cos(math.radians(150)) + Vy * math.sin(math.radians(150))) / self.wheel_radius

        # Calculate the linear velocity of the third wheel
        wheel_velocities[2] = (Vx * math.cos(math.radians(270)) + Vy * math.sin(math.radians(270))) / self.wheel_radius

        # Calculate the angular velocity of each motor
        for i in range(3):
            self.motor_pwm_values[i] = int((wheel_velocities[i] / self.wheel_radius + omega) * 255)

    def get_motor_pwm_values(self):
        return self.motor_pwm_values

    def update_position(self, dt):
        # Update position based on current velocities (Vx, Vy, omega)
        Vx, Vy, omega = self.calculate_current_velocities()
        self.x += Vx * dt
        self.y += Vy * dt
        self.theta += omega * dt

        # Ensure theta is within [-pi, pi] range
        if self.theta > math.pi:
            self.theta -= 2 * math.pi
        elif self.theta < -math.pi:
            self.theta += 2 * math.pi

    def calculate_current_velocities(self):
        # Calculate current velocities based on motor PWM values (reverse of the previous calculation)
        Vx = (self.motor_pwm_values[0] + self.motor_pwm_values[1] + self.motor_pwm_values[2]) * self.wheel_radius / (3 * 255)
        Vy = 0.0  # Assuming no lateral motion in this simplified model
        omega = (self.motor_pwm_values[0] - self.motor_pwm_values[1]) * self.wheel_radius / (3 * 255 * self.wheel_distance)

        return Vx, Vy, omega

# Define robot parameters
wheel_radius = 0.2  # Radius of the wheels in meters (20 cm)
wheel_distance = 0.4  # Distance between the wheels in meters (40 cm)

# Create a triangular-wheeled robot
robot = TriangularWheeledRobot(wheel_radius, wheel_distance)

# Set the target position and orientation
target_x = 1.0  # Target x-coordinate
target_y = 0.5  # Target y-coordinate
target_theta = math.radians(45)  # Target orientation in radians

# Simulation parameters
dt = 0.1  # Time step for simulation
sim_duration = 10.0  # Duration of the simulation in seconds

# Main simulation loop
for _ in range(int(sim_duration / dt)):
    # Update the robot's position and orientation
    robot.update_position(dt)

    # Calculate control inputs based on the target position and orientation
    robot.update_motors(target_x, target_y, target_theta)

    # Get the PWM values for each motor
    motor_pwm_values = robot.get_motor_pwm_values()

    # Print the results
    for i in range(3):
        print(f"Motor {i+1} PWM Value: {motor_pwm_values[i]}")

# Print final robot position and orientation
print(f"Final Robot Position (x, y): ({robot.x}, {robot.y})")
print(f"Final Robot Orientation (theta): {robot.theta}")
