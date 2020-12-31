import click
from flask import jsonify
from client import MADSClient
import random

client = MADSClient()

class Config(object):
    def __init__(self):
        self.script_mode=False

pass_config = click.make_pass_decorator(Config, ensure=True)

@click.group()
@click.option('--script_mode', is_flag=True, help='Outputs only IDs of inserted items (instead of JSON objects)')
@pass_config
def cli(config, script_mode):
    """Command line interface for exploring and setting up databases in MADS"""
    config.script_mode = script_mode

@cli.group()
def read():
    pass

@read.command()
@click.argument('id', type=int, required=True)
@pass_config
def object(config, id):
    """This command returns an object"""
    resp = client.get_tagset(id)
    if not config.script_mode:
        click.echo(jsonify(resp))

@read.command()
@pass_config
def tags(config):
    """This command returns all tags"""
    click.echo('Tags!')
    if not config.script_mode:
        click.echo('Writing JSON')

@read.command()
@click.argument('id', type=int, required=True)
@pass_config
def tag(config, id):
    """This command returns a tag"""
    click.echo('Tag %i!' % id)
    if not config.script_mode:
        click.echo('Writing JSON')

@read.command()
@pass_config
def tagsets(config):
    """This command returns all tagsets"""
    click.echo('Tagsets!')
    if not config.script_mode:
        click.echo('Writing JSON')

@read.command()
@click.argument('id', type=int, required=True)
@pass_config
def tagset(config, id):
    """This command returns a tagset"""
    click.echo('TagSet %i!' % id)
    if not config.script_mode:
        click.echo('Writing JSON')

@cli.group()
def insert():
    pass

@insert.command()
@click.argument('URL', type=str, required=True)
@pass_config
def object(config, url):
    """Creates an object located at URL"""
    if not config.script_mode:
        click.echo('insert object: %s' % url)
        click.echo('Writing JSON')
    else:
        click.echo(random.randrange(100)+1)

@insert.command()
@click.argument('value', type=str, required=True)
@click.argument('tagsetid', type=int, required=True)
@pass_config
def tag(config, value, tagsetid):
    """Creates a tag with VALUE in tagset ID"""
    if not config.script_mode:
        click.echo('insert tag: %s, %i!' % (value, tagsetid))
        click.echo('Writing JSON')
    else:
        click.echo(random.randrange(100)+1)

@insert.command()
@click.argument('name', type=str, required=True)
@click.argument('tagsettype', type=str, default='AlphaNumerical', required=False)
@pass_config
def tagset(config, name, tagsettype):
    """Create a tagset with name NAME of type TAGSETTYPE (default = AlphaNumerical)"""
    if not config.script_mode:
        click.echo('insert tagset: %s, %s' % (name, tagsettype))
        click.echo('Writing JSON')
    else:
        click.echo(random.randrange(100)+1)
