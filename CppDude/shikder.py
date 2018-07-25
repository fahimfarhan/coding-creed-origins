import requests
import time
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



sites = ['support@laautoservices.co.uk',
'support@leestanley.net',
'support@newkitchens.ltd.uk',
'support@nfea.com',
'support@polaris-laser.com',
'support@turbosport.net',
'support@vpress.co.uk',
'support@wastego.com',
'support@avondaleguesthouse.com',
'support@beckfoot.co.uk',
'support@ca1.co.uk',
'support@cumbriayfc.co.uk',
'support@darkseaweb.com',
'support@gincase.co.uk',
'support@golfhotelsilloth.co.uk',
'support@hutton-in-the-forest.co.uk',
'support@lovelady.co.uk',
'support@lowther.co.uk',
'support@palmyra-ltd.com',
'support@pattersonheggie.co.uk',
'support@quattro.org.uk',
'support@rathbonesofkeswick.co.uk',
'support@rosecottageguest.co.uk',
'support@sf-property.co.uk',
'support@trouthotel.co.uk',
'support@wcda.co.uk',
'support@achilles.com',
'support@adpads.co.uk',
'support@aegisengineering.co.uk',
'support@antibo.co.uk',
'support@auto-supplies.co.uk',
'support@belpernaturalhealth.co.uk',
'support@castle-cliffe.com',
'support@castlehomesderby.co.uk',
'support@charapak.co.uk',
'support@clean-slate.biz',
'support@cnainternational.co.uk',
'support@critical-skills.co.uk',
'support@darleys.com',
'support@darling-buds.com',
'support@daubneyagency.co.uk',
'support@dave-griffin.co.uk',
'support@dcil.org.uk',
'support@derbypcrepairs.com',
'support@derbyshirecountyshow.org.uk',
'support@derbyshireforklifts.co.uk',
'support@directpumpsandtanks.co.uk',
'support@dpsonline.org.uk',
'support@easibind.com',
'support@fireworksinternational.co.uk',
'support@flexi-print.co.uk',
'support@gatesuk.com',
'support@hallampolymer.com',
'support@holroyd-instruments.com',
'support@ics-ltd.co.uk',
'support@neway-training.com',
'support@norbury.derbyshire.sch.uk'
 ]

begin = ['hello']
global count
count = 0
st = time.time()
'''
for i in begin:
    try:
        for j in sites:
            try:
                count = count + 1
                mail_prototype = str(i) + str(j)
                check = get_validate(mail_prototype)
                print(str(count)+" "+str(mail_prototype)+" : "+str(check))
            except Exception as x:
                print("\n---"+str(x)+"---\n")
                pass 
        print("\n\n-------------------------------\n\n")
    except:
        pass
end = time.time()
diff = end - st
print(str(diff)+" sec\n")
'''

for j in sites:
    try:
        mail_prototype = str(j)
        check = get_validate(mail_prototype)
        print(str(mail_prototype)+" : "+str(check))
    except:
        pass

end = time.time()
diff = end - st
print(str(diff)+" sec\n")
