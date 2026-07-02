# Define global arguments
ARG DEBIAN_FRONTEND="noninteractive"
ARG USER=root

# Use the official Espressif IDF Docker image as base
# ALWAYS use a tagged version (starts with 'v') to 
# ensure build reproducibility. Release tags will change.
FROM espressif/idf:v5.5.1

# Import global arguments
ARG DEBIAN_FRONTEND
ARG USER

# Install any additional packages you want in your dev environment
RUN ["dash", "-c", "\
    apt-get update --quiet \
 && apt-get install --assume-yes --no-install-recommends --quiet \
     udev \
     vim \
 && apt-get clean \
 && apt-get purge \
 && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* \
"]

# Default to the generic ESP32 target
ENV IDF_TARGET=esp32s3
COPY .bash_aliases /home/${USER}/.bash_aliases

# Add IDF tools to bash session
RUN echo "source /opt/esp/idf/export.sh" >> /home/${USER}/.bashrc

ENV LC_ALL=C.UTF-8
ENV LANG=C.UTF-8
