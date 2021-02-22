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
@click.option('--id', type=int, required=True)
@pass_config
def object(config, id):
    """This command returns an object"""
    resp = client.get_object(id)
    if not config.script_mode:
        click.echo(resp)
    elif ('id' in resp):
        click.echo(resp['id'])
    else:
        click.echo(resp)

@read.command()
@pass_config
def tags(config):
    """This command returns all tags"""
    resp = client.get_tags()
    click.echo(resp)

@read.command()
@click.option('--id', type=int, required=True)
@pass_config
def tag(config, id):
    """This command returns a tag"""
    resp = client.get_tag(id)
    if not config.script_mode:
        click.echo(resp)
    elif ('id' in resp):
        click.echo(resp['id'])
    else:
        click.echo(resp)

@read.command()
@pass_config
def tagsets(config):
    """This command returns all tagsets"""
    resp = client.get_tagsets()
    click.echo(resp)

@read.command()
@click.option('--id', type=int, required=False, default=-1)
@click.option('--name', type=str, required=False, default='')
@pass_config
@click.pass_context
def tagset(ctx, config, id, name):
    """This command returns a tagset"""
    if (id != -1):
        resp = client.get_tagset_by_id(id)
    elif (name != ''):
        resp = client.get_tagset_by_name(name)
    else:
        click.echo(ctx.get_help())
        return

    if not config.script_mode:
        click.echo(resp)
    elif ('id' in resp):
        click.echo(resp['id'])
    else:
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
@click.argument('name', type=str, required=True)
@click.argument('description', type=str, required=True)
@click.argument('type', type=int, default=1, required=False)
@pass_config
def tagset(config, name, description, type):
    """Create a tagset NAME/DESCRIPTION of type TAGSETTYPE (default = 1 ()AlphaNumerical))
    Supported types are 1 (Alphanumerical), 2 (Numerical), 3 (Date), 4 (Time)."""
    resp = client.create_tagset(name, description, type)
    if not config.script_mode:
        click.echo(resp)
    elif ('id' in resp):
        click.echo(resp['id'])
    else:
        click.echo(resp)

@insert.group()
def tag():
    pass

@tag.command()
@click.argument('tagsetid', type=int, required=True)
@click.argument('name', type=str, required=True)
@pass_config
def alphanumerical(config, tagsetid, name):
    """Creates an alphanumerical tag with NAME in tagset ID"""
    resp = client.create_alphanumerical_tag(name, tagsetid)
    if not config.script_mode:
        click.echo(resp)
    elif ('id'in resp):
        click.echo(resp['id'])
    else:
        click.echo(resp)

@tag.command()
@click.argument('tagsetid', type=int, required=True)
@click.argument('value', type=int, required=True)
@pass_config
def numerical(config, tagsetid, value):
    """Creates a numerical tag with VALUE in tagset ID"""
    resp = client.create_numerical_tag(value, tagsetid)
    if not config.script_mode:
        click.echo(resp)
    elif ('id'in resp):
        click.echo(resp['id'])
    else:
        click.echo(resp)

@tag.command()
@click.argument('tagsetid', type=int, required=True)
@click.argument('year', type=int, required=True)
@click.argument('month', type=int, required=True)
@click.argument('day', type=int, required=True)
@pass_config
def date(config, tagsetid, year, month, day):
    """Creates a date tag with DATE in tagset ID"""
    resp = client.create_date_tag(year, month, day, tagsetid)
    if not config.script_mode:
        click.echo(resp)
    elif ('id'in resp):
        click.echo(resp['id'])
    else:
        click.echo(resp)

@insert.command()
@click.argument('tagid', type=int, required=True)
@click.argument('objectid', type=int, required=True)
@pass_config
def tagging(config, tagid, objectid):
    """Creates a tagging between Object ID and Tag ID"""
    resp = client.create_tagging(tagid, objectid)
    if not config.script_mode:
        click.echo(resp)
    elif ('tagid' in resp):
        pass
    else:
        click.echo(resp)

@cli.command()
@click.argument('csv_file', type=str, required=True)
@click.option('--prefix', type=str, default='')
@click.option('--separator', type=str, default=':')
@pass_config
def load(config, csv_file, prefix, separator):
    """Loads a file in a specific format, where each row contains:
    <file name>:<file type>:
    followed by 0 or more instances of:
    <tagset>:<tag>:
    Note: Each line must end with :, all information must be in pairs; all tagsets/tags must be alphanumerical
    """
    f = open(csv_file, 'r')
    for l in f.readlines():
        a = l.split(separator)
        resp = client.create_object(prefix+a[0], a[1])
        if ('id' in resp):
            image_id = int(resp['id'])

            i = 2;
            while (i < len(a)-1):
                resp = client.get_tagset_by_name(a[i])
                if ('id' in resp):
                    tagset_id = int(resp['id'])
                else:
                    resp = client.create_tagset(a[i], a[i], 1)
                    if ('id' in resp):
                        tagset_id = int(resp['id'])
                    else:
                        click.echo(resp)
                        exit(0)

                resp = client.create_alphanumerical_tag(a[i+1], tagset_id)
                if ('id' in resp):
                    tag_id = int(resp['id'])
                else:
                    click.echo(resp)
                    exit(0)

                resp = client.create_tagging(tag_id, image_id)
                if ('tagId' not in resp):
                    click.echo(resp)
                    exit(0)

                i += 2
        else:
            click.echo(resp)
            exit(0)

        f.close()

if __name__ == "__main__":
    cli()
