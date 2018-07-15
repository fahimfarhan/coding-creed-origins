global curr_dir
curr_dir = 0

global OBS_LEN
OBS_LEN = 10


def sonar_ok():
    print("sonar ok")
    return True

def image_ok():
    print("image ok")
    return True

def go_forward():
    print("go forward")
    return True

def go_backward():
    print("go backward")
    return True

def rotate_left():
    print("rotate left")
    return True

def rotate_right():
    print("Rotate right")
    return True

def rotate_180_degree():
    print("rotate 180 D")
    return True

def dsd_visit():
    curr_dir = 0
    while(True):
        print("ok")
        if curr_dir == 0 :
            while (sonar_ok() and image_ok()):
                go_forward()
            # kono badha paise
            if not image_ok() and sonar_ok():
                rotate_right()
                go_forward()
                rotate_right()
                curr_dir = 2
            elif not sonar_ok():
                obs_len_x = 0
                obs_len_y = 0
                while obs_len_x < OBS_LEN:
                    rotate_right()
                    go_forward()
                    obs_len_x = obs_len_x + 1
                    rotate_left()
                    if sonar_ok():
                        break
                while obs_len_y<OBS_LEN:
                    go_forward()
                    obs_len_y = obs_len_y + 1
                    rotate_left()
                    if sonar_ok():
                        break
                    else:
                        rotate_right()
                while obs_len_x != 0:
                    go_forward()
                    obs_len_x = obs_len_x - 1
                    rotate_right()
        elif curr_dir == 2:
            while sonar_ok() and image_ok():
                    go_forward()    # actually going backwards
            # obs/boundary detected
            if not image_ok() and sonar_ok():
                rotate_left()
                go_forward()
                rotate_left()
                curr_dir = 0
            elif not sonar_ok():
                obs_len_x = 0
                obs_len_y = 0
                while obs_len_x < OBS_LEN:
                    rotate_left()
                    go_forward()
                    obs_len_x = obs_len_x+1
                    rotate_right()
                    if sonar_ok():  # // end of obstacle
                        break
                while obs_len_y<OBS_LEN:
                    go_forward()
                    obs_len_y = obs_len_y + 1
                    rotate_right()
                    if sonar_ok(): 
                        break
                    else:
                        rotate_left()
                while obs_len_x != 0:
                    go_forward()
                    obs_len_x = obs_len_x - 1
                    rotate_right()
                    
                
