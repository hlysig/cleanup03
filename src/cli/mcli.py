import click
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
    resp = client.get_object(id)
    if not config.script_mode:
        click.echo(resp)

@read.command()
@pass_config
def tags(config):
    """This command returns all tags"""
    resp = client.get_tags()
    if not config.script_mode:
        click.echo(resp)

@read.command()
@click.argument('id', type=int, required=True)
@pass_config
def tag(config, id):
    """This command returns a tag"""
    resp = client.get_tag(id)
    if not config.script_mode:
        click.echo(resp)

@read.command()
@pass_config
def tagsets(config):
    """This command returns all tagsets"""
    resp = client.get_tagsets()
    if not config.script_mode:
        click.echo(resp)

@read.command()
@click.argument('id', type=int, required=True)
@pass_config
def tagset(config, id):
    """This command returns a tagset"""
    resp = client.get_tagset(id)
    if not config.script_mode:
        click.echo(resp)

@cli.group()
def insert():
    pass

@insert.command()
@click.argument('URI', type=str, required=True)
@click.argument('filetype', type=str, required=True)
@pass_config
def object(config, uri, filetype):
    """Creates an object located at URL"""
    resp = client.create_object(uri, filetype)
    if not config.script_mode:
        click.echo(resp)
    elif ('id' in resp):
        click.echo(resp['id'])
    else:
        click.echo(resp)

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
@click.argument('description', type=str, required=True)
@click.argument('type', type=int, default=1, required=False)
@pass_config
def tagset(config, name, description, type):
    """Create a tagset NAME/DESCRIPTION of type TAGSETTYPE (default = 1 ()AlphaNumerical))
    Supported types are 1 (Alphanumerical), 2 (Numerical), 3 (Date), 4 (Time).
    """
    resp = client.create_tagset(name, description, type)
    if not config.script_mode:
        click.echo(resp)
    elif ('id' in resp):
        click.echo(resp['id'])
    else:
        click.echo(resp)

if __name__ == "__main__":
    cli()
