gst-launch-1.0 filesrc location=/home/jetson/Desktop/1.yuv blocksize=4147200 ! videoparse width=1920 height=1080 format=uyvy framerate=30 ! videoconvert ! omxh264enc ! mp4mux ! filesink location=/home/jetson/Desktop/out.mp4
