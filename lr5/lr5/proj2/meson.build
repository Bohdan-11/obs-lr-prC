project('proj2-sockets', 'c', version: '1.0')
# Определяем общие исходники и объекты
sources = ['net_utils.c']
executable('server', sources + ['server.c'],
include_directories: '.')
executable('client', sources + ['client.c'],
include_directories: '.')