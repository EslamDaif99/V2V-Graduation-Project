"""project URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from django.conf import settings
from django.conf.urls.static import static
from scar import views


urlpatterns = [
    path('admin/', admin.site.urls),
    path('get_action/', views.GetAction.as_view(), name = 'action'),
    path('init/', views.Initialize_Car.as_view(), name = 'init'),
    path('inter/<str:name>', views.Initialize_Intersection.as_view(), name = 'inter'),
]



urlpatterns += static(settings.STATIC_URL, document_root=settings.STATIC_ROOT)
