import cv2
import numpy as np
import socket

def main():
    ip_address = "192.168.1.1"
    port = 8080

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((ip_address, port))

    cap = cv2.VideoCapture(0)
    while True:
        ret, frame = cap.read()
        s.sendall(frame.tobytes())
        cv2.imshow("Frame", frame)
        key = cv2.waitKey(1)
        if key == ord("q"):
            break

    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
