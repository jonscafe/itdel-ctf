# Use a lightweight Python base image
FROM python:3.9-slim

# Set environment variable
ENV PYTHONDONTWRITEBYTECODE 1
ENV PYTHONUNBUFFERED 1

# Set a working directory
WORKDIR /app

# Copy the Python script into the container
COPY checker.py /app/checker.py

# Expose the port the service will run on
EXPOSE 7035

# Command to run the Python server
CMD ["python", "checker.py"]
