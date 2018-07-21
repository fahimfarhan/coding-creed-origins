import requests

def get_validate(email):
    # email = email.lower()
    # print("inside get_validate: "+str(email))
    url = "https://api.mailgun.net/v3/" + str(email) + "/private/validate"
    r = requests.get(
        "https://api.mailgun.net/v3/address/private/validate",
        auth=("api", 'key-7512da59598befe580d52e26799b5bf9'),
        params={"address": email, "mailbox_verification": True})
    data = r.json()
    return data['mailbox_verification']



sites = ['bwcigroup.com','envirotectltd.co.uk',
'allplantsales.com',
'sabaleather.co.uk',
'sensor-technik.co.uk',
'oneonline.co.uk',
'pact-engineering.co.uk',
'www.uniquemployment.co.uk']

begin = ['info', 'hello', 'support', 'admin', 'sales', 'account']


for i in begin:
    for j in sites:
        mail_prototype = str(i)+'@' + str(j)
        check = get_validate(mail_prototype)
        print(str(mail_prototype)+" : "+str(check))
