project('proj3-html-parse', 'c', version: '1.0')
# Ищем libcurl
curl_dep = dependency('libcurl', required : false)

executable('htmlparser', ['main.c', 'htmlutils.c'],
    c_args : ['-DUSE_CURL'],
    dependencies : [ curl_dep ] )