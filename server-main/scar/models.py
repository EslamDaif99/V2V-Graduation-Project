from operator import mod
from pyexpat import model
from unicodedata import name
from django.db import models


# ('full name', 'short name')
VEHICLES = [
    ('V1', 'V1'),
    ('V2', 'V2'),
    ('V3', 'V3'),
    ('V4', 'V4')
]


PATH = [
    ('1R','1R'),
    ('1L','1L'),
    ('1S','1S'),
    ('2R','2R'),
    ('2L','2L'),
    ('2S','2S'),
    ('3R','3R'),
    ('3L','3L'),
    ('3S','3S'),
    ('4R','4R'),
    ('4L','4L'),
    ('4S','4S')
]

DIRS = [('R','R'),('L','L'),('S','S')]


class Car_X(models.Model):
    vehicle       = models.CharField(max_length=8, unique=True)
    latitude      = models.DecimalField(max_digits=10, decimal_places=8)
    longitude     = models.DecimalField(max_digits=11, decimal_places=8)
    speed         = models.PositiveIntegerField()
    direction     = models.CharField(max_length=1 , choices=DIRS)
    time          = models.TimeField(auto_now_add=True)
      
    path          = models.CharField(max_length=2 , choices=PATH)
    distance      = models.PositiveIntegerField()
    remain_time   = models.PositiveIntegerField() # time in seconds
    expected_time = models.TimeField()
    #order         = models.PositiveIntegerField() # to know position that car must stop moving
    
    action        = models.BooleanField(default = True) # True:run forward, False: stop
    stop_lat      = models.DecimalField(max_digits=10, decimal_places=8, default=0)
    stop_long     = models.DecimalField(max_digits=11, decimal_places=8, default=0)
    waiting_time  = models.PositiveIntegerField(default = 0) # time in seconds
    
    def __str__(self):
        return self.vehicle
    
    
    
class Initial(models.Model):
    vehicle      = models.CharField(max_length=8, unique=True)
    intersection = models.CharField(max_length=20, default='TEST')
    init         = models.BooleanField() # if true: forward, false : go away
    
    def __str__(self):
        return self.vehicle
    
    

class Inter(models.Model):
    name      = models.CharField(max_length=8, unique=True, default='TEST')
    latc      = models.DecimalField(max_digits=11, decimal_places=8, default=0)
    longc      = models.DecimalField(max_digits=11, decimal_places=8, default=0)
    
    lat1      = models.DecimalField(max_digits=11, decimal_places=8, default=0)
    long1      = models.DecimalField(max_digits=11, decimal_places=8, default=0)
    
    lat2      = models.DecimalField(max_digits=11, decimal_places=8, default=0)
    long2      = models.DecimalField(max_digits=11, decimal_places=8, default=0)
    
    lat3      = models.DecimalField(max_digits=11, decimal_places=8, default=0)
    long3      = models.DecimalField(max_digits=11, decimal_places=8, default=0)
    
    lat4      = models.DecimalField(max_digits=11, decimal_places=8, default=0)
    long4     = models.DecimalField(max_digits=11, decimal_places=8, default=0)
    
    X_TIME        =  models.PositiveIntegerField(default = 10) # time in seconds
    SAFE_DISTANCE = models.PositiveIntegerField(default = 15) # in meters
    DETECT_RANGE  = models.PositiveIntegerField(default = 50) # in meters
    
    def __str__(self):
        return self.name
    
    
