from setuptools import setup



setup(
    name='mcli',
    version='1.0',
    py_modules=['mcli', 'client', 'OC_pb2', 'OC_pb2_grpc'],
    install_requires=[
        'click',
        'six',
        'grpcio',
    ],
    entry_points='''
        [console_scripts]
        mcli=mcli:cli
    ''',
)
