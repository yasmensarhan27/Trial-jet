# Use an appropriate base image with necessary dependencies for building
FROM ubuntu:20.04

# Set environment variables
ENV DEBIAN_FRONTEND noninteractive
ENV LANG C.UTF-8

# Update package lists and install necessary packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    wget \
    cmake \
    g++ \
    gcc \
    binutils \
    python3 \
    python3-pip \
    git \
    libfftw3-dev \
    libboost-all-dev \
    libpython3-dev \
    libgsl-dev \
    zlib1g-dev \
    libxml2-dev \
    libxslt1-dev \
    libyaml-dev \
    libpng-dev \
    libjpeg-dev \
    libgif-dev \
    libtiff-dev \
    libx11-dev \
    libxext-dev \
    libxft-dev \
    libxpm-dev \
    libxrandr-dev \
    libxrender-dev \
    libxss-dev \
    libxt-dev \
    libxtst-dev \
    libxv-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libfreetype6-dev \
    libfontconfig1-dev \
    libpcre3-dev \
    libssl-dev \
    libbz2-dev \
    liblzma-dev \
    libsqlite3-dev \
    libncurses5-dev \
    libreadline-dev \
    libgdbm-dev \
    libdb-dev \
    tk-dev \
    libexpat1-dev \
    libffi-dev \
    libudev-dev \
    libcppunit-dev \
    libgtest-dev \
    libcurl4-openssl-dev \
    libldap2-dev \
    python3-matplotlib \
    python3-numpy \
    python3-scipy \
    && rm -rf /var/lib/apt/lists/*

# Install ROOT
RUN wget https://root.cern/download/root_v6.24.06.Linux-ubuntu20-x86_64-gcc9.4.tar.gz && \
    tar -xzvf root_v6.24.06.Linux-ubuntu20-x86_64-gcc9.4.tar.gz && \
    rm root_v6.24.06.Linux-ubuntu20-x86_64-gcc9.4.tar.gz && \
    mv root /usr/local

# Set environment variables for ROOT
ENV ROOTSYS /usr/local/root
ENV PATH $ROOTSYS/bin:$PATH
ENV LD_LIBRARY_PATH $ROOTSYS/lib:$LD_LIBRARY_PATH
ENV PYTHONPATH $ROOTSYS/lib:$PYTHONPATH

# Install Fastjet
RUN git clone https://github.com/FAST-Project/fastjet.git && \
    cd fastjet && \
    ./configure && \
    make && \
    make check && \
    make install && \
    cd .. && \
    rm -rf fastjet

# Set working directory
WORKDIR /app

# Copy your application files to the container
COPY . .

# Install Python dependencies
RUN pip3 install -r requirements.txt

# Specify the command to run on container start
CMD ["python3", "your_script.py"]
