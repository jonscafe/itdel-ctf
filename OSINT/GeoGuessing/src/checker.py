import socket
import math

# Configuration
HOST = "0.0.0.0"  # Listen on all network interfaces
PORT = 7035       # Port number
FLAG = "ITDEL{Guessing_like_Senku}"  # Define your flag here
LAT_ANSWER = -7.1042012   # Correct latitude
LON_ANSWER = 111.4243296  # Correct longitude
EARTH_RADIUS = 6371  # Earth's radius in kilometers

def haversine(lat1, lon1, lat2, lon2):
    # Convert latitude and longitude from degrees to radians
    lat1, lon1, lat2, lon2 = map(math.radians, [lat1, lon1, lat2, lon2])
    
    # Difference in coordinates
    dlat = lat2 - lat1
    dlon = lon2 - lon1
    
    # Haversine formula
    a = math.sin(dlat / 2)**2 + math.cos(lat1) * math.cos(lat2) * math.sin(dlon / 2)**2
    c = 2 * math.asin(math.sqrt(a))
    
    # Distance in kilometers
    return EARTH_RADIUS * c

def handle_client(client_socket):
    try:
        # Greet the user
        client_socket.send(b"Welcome to GeoGuessing\n")
        client_socket.send(b"Please enter coordinate integers separated by space (ex: -7.0318824 111.5206184):\n")

        # Receive data from client
        data = client_socket.recv(1024).decode().strip()
        
        # Parse user input (expects two floats)
        try:
            input_lat, input_lon = map(float, data.split())
        except ValueError:
            client_socket.send(b"Invalid input. Please provide two decimal coordinates.\n")
            client_socket.close()
            return

        # Calculate the distance using the Haversine formula
        distance = haversine(input_lat, input_lon, LAT_ANSWER, LON_ANSWER)

        # Check if the distance is within 3 km
        if distance <= 3:
            client_socket.send(f"Close enough! Here is your flag: {FLAG}\n".encode())
        else:
            client_socket.send(f"Not close enough. You're {distance:.2f} km away. Try again!\n".encode())
        
    except Exception as e:
        client_socket.send(f"An error occurred: {str(e)}\n".encode())

    # Close the client socket connection
    client_socket.close()

def start_server():
    # Create a socket (TCP)
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((HOST, PORT))
    server.listen(5)  # Listen for incoming connections

    print(f"Server listening on {HOST}:{PORT}")

    while True:
        # Accept a new connection
        client_socket, addr = server.accept()
        print(f"Accepted connection from {addr}")

        # Handle the client in a separate thread or directly
        handle_client(client_socket)

if __name__ == "__main__":
    start_server()
