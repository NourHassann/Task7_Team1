# Kinematic model

---

To get velocity in x & y direction 

```jsx
Vx = -V1*sin(phi+theta1)-V2*sin(phi+theta2)-V3*sin(phi+theta3)
Vy =  V1*cos(phi+theta1)+V2*cos(phi+theta2)+V3*cos(phi+theta3)
```

To get omega

```jsx
W = R*(V1+V2+V3)
```

In matrix form

```jsx
Vx   -sin(phi+theta1)  cos(phi+theta1)  R      V1
Vy = -sin(phi+theta1)  cos(phi+theta2)  R  *   V2
W    -sin(phi+theta3)  cos(phi+theta3)  R      V3
```

sub. with phi = 60, theta1 = 0, theta2=120, theta3 = 240, and R = 20

```jsx
Vx   -sin(60)   cos(60)   20      V1
Vy = -sin(180)  cos(180)  20  *   V2
W    -sin(300)  cos(300)  20      V3
// aprox.
Vx   -0.86   0.5   20      V1
Vy =   0     -1    20  *   V2
W    0.86    0.5   20      V3
```
