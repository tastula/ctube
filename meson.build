project('ctube', 'c')

src = [
    'src/main.c',
    'src/ct-app.c',
    'src/ct-window.c',
    'src/resources.c'
]

dps = [
    dependency('gtk+-3.0'),
    dependency('gstreamer-1.0'),
    dependency('gstreamer-video-1.0')
]

executable(
    'tube', src,
    dependencies: dps)
