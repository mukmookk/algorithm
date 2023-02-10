import sys
from math import floor
from random import randint
import pygame
from pygame.locals import QUIT

WIDTH = 20
HEIGHT = 15
SIZE = 50
NUM_OF_BOMBS = 20
EMPTY = 0
BOMB = 1
OPENED = 2
OPEN_COUNT = 0
CHECKED = [[0 for _ in range(WIDTH)] for _ in range(HEIGHT)]

pygame.init()
SURFACE = pygame.display.set_mode([WIDTH*SIZE, HEIGHT*SIZE])
FPSCLOCK = pygame.time.Clock()

def num_of_bombs(field, x_pos, y_pos):
    """ 주변에 있는 폭탄의 개수를 반환 """
    count = 0
    for yoffset in range(-1, 2):
        for xoffset in range(-1, 2):
            xpos, ypos = (x_pos + xoffset, y_pos + yoffset)
            if 0 <= xpos < WIDTH and 0 <= ypos < HEIGHT \
                and field[ypos][xpos] == BOMB:
                    count += 1
    return count

def open_title(field, x_pos, y_pos):
    """ 타일을 오픈 """
    global OPEN_COUNT
    if CHECKED[y_pos][x_pos]:
        return
    
    CHECKED[y_pos][x_pos] = True
    
    for yoffset in range(-1, 2):
        for xoffset in range(-1, 2):
            xpos, ypos = (x_pos + xoffset, y_pos + yoffset)
            if 0 <= xpos < WIDTH and 0 <= ypos < HEIGHT \
                field[ypos][xpos] = EMPTY:
                    field[ypos][xpos] = OPENED
                    OPEN_COUNT += 1
                    count = num_of_bombs(field, xpos, ypos)
                    if count == 0 and \
                        not CHECKED[ypos][xpos]:
                            open_title(field, xpos, ypos)
    
def main():
    """ 메인 루틴 """
    smallfont = pygame.font.SysFont(None, 36)
    largefont = pygame.font.SysFont(None, 72)
    message_clear = smallfont.render("!!CLEARED!!", True, (0, 255, 255))
    message_over = largefont.render("Game Over!!", True, (0, 255, 255))
    message_rect = message_clear.get_rect()
    message_rect.center = (WIDTH*SIZE/2, HEIGHT*SIZE/2)
    game_over = False
    
    field = [[EMPTY for xpos in range(WIDTH)] for ypos in range(HEIGHT)]
    
    # 폭탄을 심는다
    count = 0
    while count < NUM_OF_BOMBS:
        xpos = randint(0, WIDTH-1)
        ypos = randint(0, HEIGHT-1)
        if field[ypos][xpos] == EMPTY:
            field[ypos][xpos] = BOMB
            count += 1
    
    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
            if event.type == MOUSEBUTTONDOWN and event.button == 1:
                xpos, ypos = event.pos
                xpos = floor(xpos/SIZE)
                ypos = floor(ypos/SIZE)
                if field[ypos][xpos] == BOMB:
                    game_over = True
                else:
                    open_title(field, xpos, ypos)
        
        SURFACE.fill((0, 0, 0))
        
             
                        
            
            