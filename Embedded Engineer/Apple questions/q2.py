import random
import time

class Sound():
    def __init__(self,name='',time=0):
        self.name = name
        self.time = time
    
    def play(self):
        print('playing sound {}'.format(self.name))
        time.sleep(self.time)


def play_song_randomly(sounds):
    n = len(sounds)
    last_played = []
    while True:
        rand = random.choice(sounds)
        if(rand.name not in last_played):
            rand.play()
            last_played.append(rand.name)
        if len(last_played) == len(sounds):
            print('no sounds avaiable.')
            break


s1 = Sound('bethoven',2)
s2 = Sound('orelasan', 2)
s3 = Sound('maitre gims', 2)
sounds = [s1,s2,s3]

play_song_randomly(sounds)



        