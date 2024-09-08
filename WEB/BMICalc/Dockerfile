# Use an official Python runtime as a parent image
FROM python:3.10-slim

# Set the working directory in the container
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY app.py /app

# Copy the templates directory into the container
COPY templates/ /app/templates/

COPY flag.txt /flag.txt

# Install any needed packages specified in requirements.txt
RUN pip install --no-cache-dir flask lxml

# Make port 80 available to the world outside this container
EXPOSE 80

# Define environment variable
ENV FLASK_APP=app.py

# Run the Flask app
CMD ["python", "app.py"]
