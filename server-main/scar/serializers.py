from rest_framework import serializers
from .models import Car_X, Initial, Inter
from .models import VEHICLES
try :
    x = Inter.objects.get(name = 'TEST') #intersection
    ref = (x.latc, x.longc)
    pos = ((x.lat1, x.long1), (x.lat2, x.long2), (x.lat3, x.long3),(x.lat4, x.long4))
except:
    ref = (45, 90)
    pos = [(46,89),(46,91),(44,89),(44,91)]
class CarSerializer(serializers.ModelSerializer):
    class Meta:
        model = Car_X
        fields = ['vehicle', 'longitude', 'latitude', 'speed', 'direction']
        
        

class ResponseSerializer(serializers.ModelSerializer):
    class Meta:
        model = Car_X
        fields = ['path', 'distance', 'remain_time', 'expected_time', 'action', 'stop_lat', 'stop_long', 'waiting_time']
    
    def to_representation(self, instance):
        data                 = super().to_representation(instance)
        index = int(instance.path[0])
        location = pos[index]
        data['path'] = location
        data.update({'status': 'success', 'reference_point': ref})
        return data
                

class InitSerializer(serializers.Serializer):
    vehicle      = serializers.CharField(max_length=8)
    latitude1    = serializers.DecimalField(max_digits=10, decimal_places=8)
    longitude1   = serializers.DecimalField(max_digits=11, decimal_places=8)
    latitude2    = serializers.DecimalField(max_digits=10, decimal_places=8)
    longitude2   = serializers.DecimalField(max_digits=11, decimal_places=8)
    
    class Meta:
        fields = ['vehicle', 'longitude1', 'latitude1', 'longitude2', 'latitude2']
        

class InterSerializer(serializers.ModelSerializer):
    class Meta:
        model = Inter
        exclude = ('name', )
        