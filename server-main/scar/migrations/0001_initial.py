# Generated by Django 4.0.5 on 2022-07-02 19:19

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Car_X',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('vehicle', models.CharField(max_length=8, unique=True)),
                ('latitude', models.DecimalField(decimal_places=8, max_digits=10)),
                ('longitude', models.DecimalField(decimal_places=8, max_digits=11)),
                ('speed', models.PositiveIntegerField()),
                ('direction', models.CharField(choices=[('R', 'R'), ('L', 'L'), ('S', 'S')], max_length=1)),
                ('time', models.TimeField(auto_now_add=True)),
                ('path', models.CharField(choices=[('1R', '1R'), ('1L', '1L'), ('1S', '1S'), ('2R', '2R'), ('2L', '2L'), ('2S', '2S'), ('3R', '3R'), ('3L', '3L'), ('3S', '3S'), ('4R', '4R'), ('4L', '4L'), ('4S', '4S')], max_length=2)),
                ('distance', models.PositiveIntegerField()),
                ('remain_time', models.PositiveIntegerField()),
                ('expected_time', models.TimeField()),
                ('action', models.BooleanField(default=True)),
                ('stop_lat', models.DecimalField(decimal_places=8, default=0, max_digits=10)),
                ('stop_long', models.DecimalField(decimal_places=8, default=0, max_digits=11)),
                ('waiting_time', models.PositiveIntegerField(default=0)),
            ],
        ),
        migrations.CreateModel(
            name='Initial',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('vehicle', models.CharField(max_length=8, unique=True)),
                ('intersection', models.CharField(default='TEST', max_length=20)),
                ('init', models.BooleanField()),
            ],
        ),
        migrations.CreateModel(
            name='Inter',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(default='TEST', max_length=8, unique=True)),
                ('latc', models.DecimalField(decimal_places=8, default=0, max_digits=11)),
                ('longc', models.DecimalField(decimal_places=8, default=0, max_digits=11)),
                ('lat1', models.DecimalField(decimal_places=8, default=0, max_digits=11)),
                ('long1', models.DecimalField(decimal_places=8, default=0, max_digits=11)),
                ('lat2', models.DecimalField(decimal_places=8, default=0, max_digits=11)),
                ('long2', models.DecimalField(decimal_places=8, default=0, max_digits=11)),
                ('lat3', models.DecimalField(decimal_places=8, default=0, max_digits=11)),
                ('long3', models.DecimalField(decimal_places=8, default=0, max_digits=11)),
                ('lat4', models.DecimalField(decimal_places=8, default=0, max_digits=11)),
                ('long4', models.DecimalField(decimal_places=8, default=0, max_digits=11)),
                ('X_TIME', models.PositiveIntegerField(default=10)),
                ('SAFE_DISTANCE', models.PositiveIntegerField(default=15)),
                ('DETECT_RANGE', models.PositiveIntegerField(default=50)),
            ],
        ),
    ]